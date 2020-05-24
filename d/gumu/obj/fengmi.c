// fengmi.c 玉蜂蜜
// By Lgg,1998.9

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("玉蜂蜜", ({"mi", "fengmi", "feng mi"}));
        set_weight(750);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一罐玉蜂酿成的蜜。\n");
                set("unit", "罐");
                set("value", 20);
                set("max_liquid", 12);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "fengmi",
                "name": "蜂蜜",
                "remaining": 12,
                "drunk_supply": 9,
        ]));
}

