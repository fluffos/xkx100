// heisuo.c  黑索

#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(BLK"黑索"NOR, ({ "heisuo", "bian" }));
	set_weight(500);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根长索，通体黝黑无光，舞动之时瞧不见半点影子。\n");
		set("value", 0);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一条$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	setup();
}
