stock IsPlayerModerInWorld(playerid)
{
  if(pInfo[playerid][pModer] >= ***) return true; // вместо звездочек подставить проверку на ур. модерки которым разрешен /cb
  if(worldArray[world][wOwner] == playerid) return true;
  return false;
}
