stock IsValidBlock(blockid, world)
{
    if (0 > blockid > GetWorldMaxBlock(world)) {
        return false;
    }
}