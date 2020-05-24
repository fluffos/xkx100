// laitangyuan.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("赖汤圆", ({ "lai tangyuan", "tangyuan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一碗香喷喷、甜丝丝的赖汤圆。\n");
                set("unit", "碗");
                set("value", 0);
                set("food_remaining", 5);
                set("food_supply", 30);
        }
}
