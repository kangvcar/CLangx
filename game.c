#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 10

typedef struct
{
    char* name;
    char* description;
} Item;

typedef struct
{
    char* description;
    int id;
    Item* item;
} Scene;

typedef struct
{
    Scene* location;
    Item* inventory[MAX_ITEMS];
    int num_items;
} Player;



Scene start = {"你在一个安静的小屋里。有一条通向森林的小径。", 1};
Scene forest = {"你在一个森林里。有一条通向小屋的小径，还有一条通向一个看起来阴森的洞穴。", 2};
Scene cave = {"你在一个黑暗的洞穴里。只有一个出口，通向森林。", 3};

Item key = {"钥匙", "一个小钥匙。可能可以打开某些东西。"};


int main(){
    Player player = {&start};
    start.item = &key;
    while (1)
    {
        // 打印玩家所在的位置
        printf("%s\n", player.location->description);
        // 如果玩家所在的位置有物品，打印物品的信息
        if (player.location->item != NULL)
        {
            printf("你看到了一个%s： %s\n", player.location->item->name, player.location->item->description);
        }
        // 玩家输入动作
        char action[20];
        scanf("%s", action);
        // 玩家执行动作
        if (strcmp(action, "拾取物品") == 0) {
            // 如果玩家所在的位置有物品，玩家可以拾取物品
            if (player.num_items < MAX_ITEMS && player.location->item != NULL)
            {
                player.inventory[player.num_items] = player.location->item;
                player.num_items++;
                printf("你拾取了%s。\n", player.location->item->name);
                player.location->item = NULL;
                printf("你拾取了物品。\n");
            }else{
                printf("你不能这么做。\n");
            }
        }
        // 如果玩家输入了“查看背包”，打印背包里的物品
        if (strcmp(action, "查看背包") == 0)
        {
            if (player.num_items == 0)
            {
                printf("你的背包是空的。\n");
            }else{
                printf("你的背包里有：\n");
                for (int i = 0; i < player.num_items; i++)
                {
                    printf("%s: %s\n", player.inventory[i]->name, player.inventory[i]->description);
                }
            }
        }
        // 如果玩家输入了“前往”，玩家可以移动到其他位置
        if (player.location->id == 1 && strcmp(action, "前往森林") == 0)
        {
            player.location = &forest;
        }
        if (player.location->id == 2 && strcmp(action, "前往小屋") == 0)
        {
            player.location = &start;
        }
        if (player.location->id == 2 && strcmp(action, "前往洞穴") == 0) {
            player.location = &cave;
        }

    }
    return 0;
}