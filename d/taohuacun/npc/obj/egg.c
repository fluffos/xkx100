#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "鸡蛋" NOR,({"egg"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个鸡蛋。\n");
                set("unit", "个");
        }
}