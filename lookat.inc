/*

                    ooooo      ooo       .o.       ooooooooooooo ooooo oooooo     oooo       .o.        .oooooo..o 
                    `888b.     `8'      .888.      8'   888   `8 `888'  `888.     .8'       .888.      d8P'    `Y8 
                    8 `88b.    8      .8"888.          888       888    `888.   .8'       .8"888.     Y88bo.      
                    8   `88b.  8     .8' `888.         888       888     `888. .8'       .8' `888.     `"Y8888o.  
                    8     `88b.8    .88ooo8888.        888       888      `888.8'       .88ooo8888.        `"Y88b 
                    8       `888   .8'     `888.       888       888       `888'       .8'     `888.  oo     .d8P 
                    o8o        `8  o88o     o8888o     o888o     o888o       `8'       o88o     o8888o 8""88888P'  


        native GetPlayerViewDirection(playerid, Float:scale, &Float:x, &Float:y, &Float:z);

        native IsPointLookingAtPoint(playerid, Float:x, Float:y, Float:z);
        native IsPlayerLookingAtPlayer(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
        native IsPlayerLookingAtVehicle(playerid, targetid);
        native IsPlayerLookingAtObject(playerid, targetid);
        native IsPlayerLookingAtActor(playerid, targetid);
        IsLookingAtEntity(playerid, entityType, entityID, Float:range = MAX_RANGE_DISTANCE)
                                                                                          
*/

#if defined _lookat_included
	#endinput
#endif
#define _lookat_included

                // Definers
#define                      MAX_RANGE_DISTANCE     (2.0)
#define                      MAX_SCALE_DISTANCE     (5.0)



/*

                    .oooooo..o ooooooooooooo   .oooooo.     .oooooo.   oooo    oooo  .oooooo..o
                    d8P'    `Y8 8'   888   `8  d8P'  `Y8b   d8P'  `Y8b  `888   .8P'  d8P'    `Y8
                    Y88bo.           888      888      888 888           888  d8'    Y88bo.     
                    `"Y8888o.       888      888      888 888           88888[       `"Y8888o. 
                        `"Y88b      888      888      888 888           888`88b.         `"Y88b
                    oo     .d8P      888      `88b    d88' `88b    ooo   888  `88b.  oo     .d8P
                    8""88888P'      o888o      `Y8bood8P'   `Y8bood8P'  o888o  o888o 8""88888P' 

*/

stock GetPlayerViewDirection(playerid, Float:scale, &Float:x, &Float:y, &Float:z)
{
    new Float:camX, Float:camY, Float:camZ;
    new Float:posX, Float:posY, Float:posZ;

    GetPlayerCameraPos(playerid, camX, camY, camZ);
    GetPlayerCameraFrontVector(playerid, posX, posY, posZ);

    x = camX + posX * scale;
    y = camY + posY * scale;
    z = camZ + posZ * scale;
}

stock bool:IsFloatBetween(Float:value, Float:center, Float:range = MAX_RANGE_DISTANCE)
{
    return (value >= (center - range) && value <= (center + range));
}

stock bool:IsPointLookingAtPoint(playerid, Float:x, Float:y, Float:z)
{
    new Float:posX, Float:posY, Float:posZ;
    GetPlayerViewDirection(playerid, MAX_SCALE_DISTANCE, posX, posY, posZ);
    if(IsFloatBetween(posX, x) && IsFloatBetween(posY, y) && IsFloatBetween(posZ, z))
        return true;

    return false;
}

stock IsPlayerLookingAtPlayer(playerid, targetid, Float:range = MAX_RANGE_DISTANCE)
{
    new Float:posX, Float:posY, Float:posZ;
    GetPlayerViewDirection(playerid, MAX_SCALE_DISTANCE, posX, posY, posZ);

    return bool:(IsPlayerInRangeOfPoint(targetid, range, posX, posY, posZ));
}

stock bool:IsPlayerLookingAtVehicle(playerid, targetid)
{
    new Float:posX, Float:posY, Float:posZ;
    GetVehiclePos(targetid, posX, posY, posZ);

    return IsPointLookingAtPoint(playerid, posX, posY, posZ);
}

stock bool:IsPlayerLookingAtObject(playerid, targetid)
{
    new Float:posX, Float:posY, Float:posZ;
    GetObjectPos(targetid, posX, posY, posZ);

    return IsPointLookingAtPoint(playerid, posX, posY, posZ);
}

stock bool:IsPlayerLookingAtActor(playerid, targetid)
{
    new Float:posX, Float:posY, Float:posZ;
    GetActorPos(targetid, posX, posY, posZ);

    return IsPointLookingAtPoint(playerid, posX, posY, posZ);
}

//entityType: 1 = player, 2 = vehicle, 3 = object, 4 = actor.
stock bool:IsLookingAtEntity(playerid, entityType, entityID, Float:range = MAX_RANGE_DISTANCE)
{
    switch(entityType)
    {
        case 1: return IsPlayerLookingAtPlayer(playerid, entityID, range);
        case 2: return IsPlayerLookingAtVehicle(playerid, entityID);
        case 3: return IsPlayerLookingAtObject(playerid, entityID);
        case 4: return IsPlayerLookingAtActor(playerid, entityID);
    }
    return false;
}