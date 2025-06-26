# 👁️ LookAt

A Pawn include for checking whether a player is looking at another entity using camera direction. Ideal for interaction systems, NPC detection, immersive dialogues, and dynamic targeting.

---

## 📦 Installation

1. Download the latest version of `lookat.inc`.
2. Place the file inside your server’s `include/` folder.
3. Include it in your gamemode or filterscript:

```pawn
#include <lookat>
```

---

## ⚙️ Native Functions

```pawn
native GetPlayerViewDirection(playerid, Float:scale, &Float:x, &Float:y, &Float:z);

native bool:IsFloatBetween(Float:value, Float:center, Float:range = 2.0);
native bool:IsPointLookingAtPoint(playerid, Float:x, Float:y, Float:z);
native bool:IsPlayerLookingAtPlayer(playerid, targetid, Float:range = 2.0);
native bool:IsPlayerLookingAtVehicle(playerid, vehicleid);
native bool:IsPlayerLookingAtObject(playerid, objectid);
native bool:IsPlayerLookingAtActor(playerid, actorid);
native bool:IsLookingAtEntity(playerid, entityType, entityID, Float:range = 2.0);
```

> \[!IMPORTANT]
>
> * `scale`: Distance forward from the camera to simulate a "line of sight".
> * `range`: How close the target must be to the center of view to be considered "looked at".

---

## 🧠 Entity Types

| ID | Type    |
| -- | ------- |
| 1  | Player  |
| 2  | Vehicle |
| 3  | Object  |
| 4  | Actor   |

---

## 🧪 Example Usage

```pawn
CMD:interact(playerid)
{
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        if (i != playerid && IsPlayerLookingAtPlayer(playerid, i))
        {
            SendClientMessage(playerid, -1, "Voce esta olhando para um jogador!");
        } 
        else
        if (IsPlayerLookingAtVehicle(playerid, i))
		{
			SendClientMessage(playerid, -1, "Voce esta olhando para o seu veiculo!");
		}
    }
    return 1;
}
```

---

## 📷 Demo Video (soon)

🚧 *In development — will be available soon.*

---

## 🙌 Credits

* **Ortex** – Original author and developer of the include.

---

## 🌐 Other Languages

* [Português](https://github.com/dev-ortex/lookat/blob/main/README-pt.md)
* [English](https://github.com/dev-ortex/lookat/blob/main/README.md)