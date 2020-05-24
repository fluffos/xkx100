#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "豆腐" NOR,({"doufu"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "几块鲜嫩的豆腐。\n");
                set("unit", "些");
        }
}