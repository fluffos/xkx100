#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "白菜" NOR,({"baicai"}));
	set_weight(1000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一筐白菜。\n");
                set("unit", "筐");
        }
}