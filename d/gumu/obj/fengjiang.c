// fengjiang.c 玉蜂浆
// By Lgg,1998.9

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("玉蜂浆", ({"jiang", "feng jiang"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一瓶用玉蜂巢捣成的浆。\n");
                set("unit", "瓶");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
