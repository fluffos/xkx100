#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"九黄饼"NOR, ({"jiuhuang bing","bing"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "荆州名点，酥松香甜。\n");
                set("unit", "块");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}

