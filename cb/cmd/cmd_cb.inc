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

Resource:RulesMenu(menu)
{
    new str[1024] = "{FFFFFF}";
    
    if(menu == -1) // Главное меню условий
    {
        format(str, sizeof(str), "N/A (удалить условие)");
        format(str, sizeof(str, "%s\nСвоё значение");
        format(str, sizeof(str), "%s\nПараметры игрока", str);
        format(str, sizeof(str), "%s\nПараметры мира", str);
        format(str, sizeof(str), "%s\nОнлайн команды", str);
        format(str, sizeof(str), "%s\nМассив игрока", str);
        format(str, sizeof(str), "%s\nМассив сервера", str);
        format(str, sizeof(str), "%s\nМассив транспорта", str);
        format(str, sizeof(str), "%s\nМассив коллбека", str);
        
        return str;
    }
   else if(menu == 2) // Параметры игрока
    {
        format(str, sizeof(str), "Уровень HP");
        format(str, sizeof(str), "%s\nУровень ARM", str);
        format(str, sizeof(str), "%s\nОчки (в TABe)", str);
        format(str, sizeof(str), "%s\nДеньги", str);
        format(str, sizeof(str), "%s\nID команды", str);
        format(str, sizeof(str), "%s\nУровень розыска", str);
        format(str, sizeof(str), "%s\nСкорость", str);
        format(str, sizeof(str), "%s\nID оружия", str);
        format(str, sizeof(str), "%s\nID транспорта", str);
        format(str, sizeof(str), "%s\nID игрока", str);
        format(str, sizeof(str), "%s\nHP транспорта", str);
        format(str, sizeof(str), "%s\nМодель ТС, str);
        format(str, sizeof(str), "%s\nУровень модера", str);
        format(str, sizeof(str), "%s\nИнтерьер", str);
        format(str, sizeof(str), "%s\nКоординаты XYZ", str);
        format(str, sizeof(str), "%s\nКоордината X", str);
        format(str, sizeof(str), "%s\nКоордината Y", str);
        format(str, sizeof(str), "%s\nКоордината Z", str);
        format(str, sizeof(str), "%s\nЦвет транспорта", str);
        format(str, sizeof(str), "%s\nВремя", str);
        format(str, sizeof(str), "%s\nПогода", str);
        format(str, sizeof(str), "%s\nПоворот игрока", str);
        format(str, sizeof(str), "%s\nID транспорта (в мире)", str);
        format(str, sizeof(str), "%s\nID транспорта (на сервере)", str);
        format(str, sizeof(str), "%s\nID района", str);
        format(str, sizeof(str), "%s\nПинг игрока", str);
        format(str, sizeof(str), "%s\nПакеты NetStat", str);
        format(str, sizeof(str), "%s\nAFK (кол-во секунд)", str);
        format(str, sizeof(str), "%s\nНаличие прицепа", str);
        format(str, sizeof(str), "%s\nID аккаунта", str);
        format(str, sizeof(str), "%s\nВладелец ТС", str);
        
        return str;
    
    }
    else if(menu == 3) // Параметры мира
    {
        format(str, sizeof(str), "Онлайн мира");
        format(str, sizeof(str), "%s\nTimestamp", str);
        format(str, sizeof(str), "%s\nВремя мира", str);
        format(str, sizeof(str), "%s\nПогода мира", str);
    
        return str;
    }
    else if(menu == 4) // Онлайн команды
    {
        format(str, sizeof(str), "Онлайн команды [ 1 ]");
        format(str, sizeof(str), "%s\nОнлайн команды [ 2 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 3 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 4 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 5 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 6 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 7 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 8 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 9 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 10 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 11 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 12 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 13 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 14 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 15 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 16 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 17 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 18 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 19 ]", str);
        format(str, sizeof(str), "%s\nОнлайн команды [ 20 ]", str);
        
        return str;
    }
    else if(menu == 5) // Массив игрока
    {
        format(str, sizeof(str), "М/И [ 0 ]");
        format(str, sizeof(str), "%s\nМ/И [ 1 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 2 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 3 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 4 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 5 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 6 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 7 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 8 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 9 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 10 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 11 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 12 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 13 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 14 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 15 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 16 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 17 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 18 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 19 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 20 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 21 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 22 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 23 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 24 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 25 ]", str);
        format(str, sizeof(str), "%s\nМ/И [ 26 ]", str);
        
    
        return str;
    }
    else if(menu == 6) // Массив сервера
    {
        format(str, sizeof(str), "М/C [ 0 ]");
        format(str, sizeof(str), "%s\nM/C [ 1 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 2 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 3 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 4 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 5 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 6 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 7 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 8 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 9 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 10 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 11 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 12 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 13 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 14 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 15 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 16 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 17 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 18 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 19 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 20 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 21 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 22 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 23 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 24 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 25 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 26 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 27 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 28 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 29 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 30 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 31 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 32 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 33 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 34 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 35 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 36 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 37 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 38 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 39 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 40 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 41 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 42 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 43 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 44 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 45 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 46 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 47 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 48 ]", str);
        format(str, sizeof(str), "%s\nM/C [ 49 ]", str);
    
        return str;
    }
    else if(menu == 7) // Массив транспорта
    {
        format(str, sizeof(str), "М/ТС [ 0 ]");
        format(str, sizeof(str), "%s\nM/ТС [ 1 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 2 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 3 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 4 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 5 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 6 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 7 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 8 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 9 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 10 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 11 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 12 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 13 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 14 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 15 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 16 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 17 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 18 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 19 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 20 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 21 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 22 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 23 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 24 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 25 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 26 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 27 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 28 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 29 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 30 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 31 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 32 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 33 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 34 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 35 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 36 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 37 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 38 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 39 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 40 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 41 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 42 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 43 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 44 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 45 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 46 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 47 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 48 ]", str);
        format(str, sizeof(str), "%s\nM/ТС [ 49 ]", str);
    
        return str;
    }
    else if(menu == 8) // Меню коллбека
    {
        *позже вставим*
        
        return str;
    }
    
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

    return true;
}
