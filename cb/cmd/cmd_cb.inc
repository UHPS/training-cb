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
    Тут в будущем будут проверки есть доступ у игрока к КБ данной cmd или нет
*/
Access::cb(playerid)
{
    return true;
}

/**
    Тут валидируются параметры и т.д.
*/
Request:cb(playerid, blockid)
{
    if (!IsValidBlock(blockid)) {
        SendServerMessage(playerid, "Неверно указан ID блока");
        return false;
    }

    return true;
}

/**
    Формировка строки для передачи в диалог
*/
Resource:BlockMenu(world, blockid)
{
    new str[1024] = "{FFFFFF}";

    format(str, sizeof(str), "%sИмя\t[ %s ]", str, GetBlockName(world, blockid));
    format(str, sizeof(str), "%sСтатус\t[ %s ]", str, GetBlockStatus(world, blockid)); // Этой функции нет, надо создать
    format(str, sizeof(str), "%sБинд\t[ %s ]", str, GetBlockBind(world, blockid)); // Этой функции нет, надо создать
    format(str, sizeof(str), "%sУсловий\t[ %d ]", str, GetBlockRulesCount(world, blockid)); // Этой функции нет, надо создать
    format(str, sizeof(str), "%Коллбеков\t[ %d ]", str, GetBlockCallbackCount(world, blockid)); // Этой функции нет, надо создать
    format(str, sizeof(str), "%Функций\t[ %d ]", str, GetBlockCallbackCount(world, blockid)); // Этой функции нет, надо создать
    format(str, sizeof(str), "%Активация\t[ %s ]", str, GetBlockActivation(world, blockid)); // Этой функции нет, надо создать

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
    Это просто отображение диалога
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