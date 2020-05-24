#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("牛肉",({"beef"}));
	set_weight(500);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块牛肉。\n");
                set("unit", "块");
        }
}