#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "羊羔坐臀" NOR,({"zuotun"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块羊羔坐臀。\n");
                set("unit", "块");
        }
}