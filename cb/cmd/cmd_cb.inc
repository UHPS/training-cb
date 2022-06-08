CMD:cb(playerid, params[])
{
    if (!Can->cb(playerid)) {
        return true;
    }

    extract params -> new blockid; else {
        return SendServerMessage(playerid, "/cb <id>");
    }

    if (!Validate->cb(playerid, blockid)) {
        return true;
    }

    SetPlayerBlock(playerid, blockid);

    Show->BlockMenu(playerid);
    return true;
}

/**
    Òóò â áóäóùåì áóäóò ïðîâåðêè åñòü äîñòóï ó èãðîêà ê ÊÁ äàííîé cmd èëè íåò
*/
Access::cb(playerid)
{
    return true;
}

/**
    Òóò âàëèäèðóþòñÿ ïàðàìåòðû è ò.ä.
*/
Request:cb(playerid, blockid)
{
    if (!IsValidBlock(blockid)) {
        SendServerMessage(playerid, "Íåâåðíî óêàçàí ID áëîêà");
        return false;
    }

    return true;
}

/**
    Ôîðìèðîâêà ñòðîêè äëÿ ïåðåäà÷è â äèàëîã
*/
Resource:BlockMenu(world, blockid)
{
    new str[1024] = "{FFFFFF}";

    format(str, sizeof(str), "%sÈìÿ\t[ %s ]", str, GetBlockName(world, blockid));
    format(str, sizeof(str), "%sÑòàòóñ\t[ %s ]", str, GetBlockStatus(world, blockid)); // Ýòîé ôóíêöèè íåò, íàäî ñîçäàòü
    format(str, sizeof(str), "%sÁèíä\t[ %s ]", str, GetBlockBind(world, blockid)); // Ýòîé ôóíêöèè íåò, íàäî ñîçäàòü
    format(str, sizeof(str), "%sÓñëîâèé\t[ %d ]", str, GetBlockRulesCount(world, blockid)); // Ýòîé ôóíêöèè íåò, íàäî ñîçäàòü
    format(str, sizeof(str), "%Êîëëáåêîâ\t[ %d ]", str, GetBlockCallbackCount(world, blockid)); // Ýòîé ôóíêöèè íåò, íàäî ñîçäàòü
    format(str, sizeof(str), "%Ôóíêöèé\t[ %d ]", str, GetBlockCallbackCount(world, blockid)); // Ýòîé ôóíêöèè íåò, íàäî ñîçäàòü
    format(str, sizeof(str), "%Àêòèâàöèÿ\t[ %s ]", str, GetBlockActivation(world, blockid)); // Ýòîé ôóíêöèè íåò, íàäî ñîçäàòü

    return str;
}

Access::BlockMenu(playerid)
{
    return true;
}

Request:BlockMenu(playerid, response, listitem, inputtext)
{
    if (!response) {
        return false
    }

    return true;
}

/**
    Ýòî ïðîñòî îòîáðàæåíèå äèàëîãà
*/
View:BlockMenu(playerid)
{
    if (!Can->BlockMenu(playerid)) {
        return false;
    }

    return Dialog_Show(
        playerid,
        BlockMenu,
        DIALOG_STYLE_TABLIST,
        " ",
        Collect->BlockMenu(GetPlayerVirtualWorld(playerid), GetPlayerBlock(playerid))
        "Y",
        "X"
    );
}

Dialog:BlockMenu(playerid, response, listitem, inputtext[])
{
    if (!Can->BlockMenu(playerid)) {
        return false;
    }

    if (!Validate->BlockMenu(playerid, response, listitem, inputtext)) {
        return false;
    }

    if(listitem == 2) return Show->MenuSetBind(playerid);
    return true;
}

Viev:MenuSetBind(playerid)
{
        return Dialog_Show(
        playerid,
        MenuSetBind,
        DIALOG_STYLE_INPUT,
        " ",
        "Укажите аллиас (до 12 символов):",
        "Y",
        "X"
    );
}

Dialog:MenuSetBind(playerid, response, listitem, inputtext[])
{
    if(!response) return Show->BlockMenu(playerid);
    
    if(strlen(inputtext) >= 12) strdel(inputtext,12,strlen(inputtext));
    
    SetBlockBind(*);
    Show->BlockMenu(playerid);

    return true;
}
