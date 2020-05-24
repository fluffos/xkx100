#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(CYN "豆瓣" NOR,({"bean"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一篮豆瓣。\n");
                set("unit", "篮");
        }
}