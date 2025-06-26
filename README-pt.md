Claro! Aqui está a versão em **Português** do `README.md` para sua include `lookat.inc` — com linguagem clara, didática e no mesmo padrão do exemplo anterior:

---

# 👁️ LookAt

Uma include para **Pawn** que permite detectar se um jogador está olhando para uma entidade (outro player, veículo, objeto ou actor), utilizando a direção da câmera. Ideal para sistemas de interação, diálogos imersivos, detecção de presença e outros recursos avançados de Roleplay.

---

## 📦 Instalação

1. Baixe a versão mais recente da `lookat.inc`.
2. Coloque o arquivo dentro da pasta `include/` do seu servidor.
3. Inclua no seu gamemode ou filterscript:

```pawn
#include <lookat>
```

---

## ⚙️ Funções Nativas

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

> \[!IMPORTANTE]
>
> * `scale`: Distância à frente da câmera usada para simular o “olhar” do jogador.
> * `range`: Distância de tolerância para considerar que o jogador está olhando diretamente para o alvo.

---

## 🔢 Tipos de Entidades

| ID | Tipo    |
| -- | ------- |
| 1  | Player  |
| 2  | Veículo |
| 3  | Objeto  |
| 4  | Actor   |

---

## 🧪 Exemplo de Uso

```pawn
CMD:interagir(playerid)
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

## 📷 Vídeo de Demonstração

🚧 *Em desenvolvimento — será publicado em breve.*

---

## 🙌 Créditos

* **Ortex** – Autor e desenvolvedor da include original.

---

## 🌐 Outros Idiomas

* [Português](https://github.com/dev-ortex/lookat/blob/main/README-pt.md)
* [English](https://github.com/dev-ortex/lookat/blob/main/README.md)