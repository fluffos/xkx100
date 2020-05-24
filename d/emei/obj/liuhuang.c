// liuhuang.c 硫磺
inherit ITEM;
void create()
{
        set_name("硫磺", ({"liuhuang"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块黄色的硫磺晶体。\n");
                set("unit", "块");
                set("value", 10);
        }
}
