### Подклюение файлов:

В каждой папке должен быть init.inc файл по принципу матрешки.
К примеру в корне есть 

init.inc
```c
#include "../lib/cb/init"
```

/lib/cb/ini.inс
```c
#include "../lib/cb/function/init"
```

/lib/cb/function/init
```c
#include "../lib/cb/function/IsValidBlock"
#include "../lib/cb/function/GetPlayerBlock"
#include "../lib/cb/function/SetPlayerBlock"
#include "../lib/cb/function/GetBlockName"
#include "../lib/cb/function/SetBlockName"
```
____
### Хранение файлов:
Каждая cmd должна лежать в отдельном файле!
```c
/cb/cmd/cmd_cb.inc
/cb/cmd/cmd_cbdell.inc
/cb/cmd/cmd_cbedit.inc
```

Функции которые могут использоваться в нескольких местах так же должны лежать каждая в своем файле!

```c
/cb/function/GetBlockName.inc
/cb/function/SetBlockName.inc
/cb/function/GetPlayerBlock.inc
```

В коде не должно быть переменных негде кроме точек входа/выхода к примеру:
```c
/cb/function/GetBlockName.inc
/cb/function/SetBlockName.inc
```

Хранить переменные для КБ или игрока в этих файлах - ошибка.
```c
/cb/cmd/cmd_cb.inc
/cb/cmd/cmd_cbdell.inc
/cb/cmd/cmd_cbedit.inc
```

В процессе разработки нужно будет много данных о КБ и игроке. Но мы будем идти по пути подставных функций.
Пример: Предположим вам необходимо получить свободных слот КБ. Создается функция.
```c
/cb/function/GetBlockFreeSlot.inc

stock GetBlockFreeSlot(world)
{
  return 1;
}
```
В такие функции я буду подставлять необходимые переменные.

Более наглядный пример:
```c
Resource:BlockMenu(world, blockid)
{
    new str[1024] = "{FFFFFF}";

    format(str, sizeof(str), "%sИмя\t[ %s ]", str, GetBlockName(world, blockid));
    format(str, sizeof(str), "%sСтатус\t[ %s ]", str, GetBlockStatus(world, blockid));
    format(str, sizeof(str), "%sБинд\t[ %s ]", str, GetBlockBind(world, blockid));
    format(str, sizeof(str), "%sУсловий\t[ %d ]", str, GetBlockRulesCount(world, blockid));
    format(str, sizeof(str), "%Коллбеков\t[ %d ]", str, GetBlockCallbackCount(world, blockid));
    format(str, sizeof(str), "%Функций\t[ %d ]", str, GetBlockCallbackCount(world, blockid));
    format(str, sizeof(str), "%Активация\t[ %s ]", str, GetBlockActivation(world, blockid));

    return str;
}
```
____
#### Для того чтобы проще было в будущем работать с кодом необходимо придерживаться костылей.

#### Показа диалога для пользователя

#### Пример #1
```c

CMD:cb(playerid, params[])
{
    Show->BlockMenu(playerid);
    return true;
}

View:BlockMenu(playerid)
{
    return Dialog_Show(
        playerid,
        BlockMenu,
        DIALOG_STYLE_TABLIST,
        " ",
        "Hello World",
        "Y",
        "X"
    );
}

```
____
#### Проверка прав доступа

#### Пример #1
```c
Access:cb(playerid)
{
    if (playerid != 1) {
      SendServerMessage(playerid, "Только игроки с ID #1 могут использовать данную команду");
      return false;
    }
    return true;
}

CMD:cb(playerid, params[])
{
    if (!Can->cb(playerid)) {
        return true;
    }
    
    return true;
}
```

#### Пример #2
```c
Access:BlockMenu(playerid)
{
    if (GetPlayerVirtualWorld(playerid == 0)) {
      SendServerMessage(playerid, "Ты думал баг найти? А баг нашел тебя");
      return false;
    }
    
    return true;
}

Dialog:BlockMenu(playerid, response, listitem, inputtext[])
{
    if (!Can->BlockMenu(playerid)) {
        return false;
    }
    
    return true;
}
```
____
#### Проверка входных данных

#### Пример #1
```c
Request:cb(playerid, blockid)
{
    if (blockid < 0) {
        SendServerMessage(playerid, "Неверно указан ID блока");
        return false;
    }

    return true;
}

CMD:cb(playerid, params[])
{
    extract params -> new blockid; else {
        return SendServerMessage(playerid, "/cb <id>");
    }

    if (!Validate->cb(playerid, blockid)) {
        return true;
    }
    
    return true;
}
```

#### Пример #2
```c
Request:BlockMenu(playerid, response, listitem, inputtext)
{
    if (!response) {
        SendServerMessage(playeid, "Вы тыкнули отмену. Диалог будет закрыт");
        return false
    }

    return true;
}

Dialog:BlockMenu(playerid, response, listitem, inputtext[])
{
    if (!Validate->BlockMenu(playerid, response, listitem, inputtext)) {
        return false;
    }

    return true;
}
```
____
#### Сборка форматируемых строк

#### Пример
```c
Resource:BlockMenu(world, blockid)
{
    new str[1024] = "{FFFFFF}";

    format(str, sizeof(str), "%sИмя\t[ %s ]", str, GetBlockName(world, blockid));
    format(str, sizeof(str), "%sСтатус\t[ %s ]", str, GetBlockStatus(world, blockid));
    format(str, sizeof(str), "%sБинд\t[ %s ]", str, GetBlockBind(world, blockid));
    format(str, sizeof(str), "%sУсловий\t[ %d ]", str, GetBlockRulesCount(world, blockid));
    format(str, sizeof(str), "%Коллбеков\t[ %d ]", str, GetBlockCallbackCount(world, blockid));
    format(str, sizeof(str), "%Функций\t[ %d ]", str, GetBlockCallbackCount(world, blockid));
    format(str, sizeof(str), "%Активация\t[ %s ]", str, GetBlockActivation(world, blockid));

    return str;
}

View:BlockMenu(playerid)
{
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
```
