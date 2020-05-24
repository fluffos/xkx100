// paomo.c 
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"羊肉泡馍"NOR, ({"yangrou paomo", "paomo"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一碗热乎乎香喷喷的羊肉汤，泡上捻得碎碎的馍，真解乏！\n");
		set("unit", "碗");
 		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
}
