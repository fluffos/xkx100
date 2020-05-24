// qiner.c 琴儿

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("琴儿", ({ "qin er", "qiner", "qin" }) );
	set("gender", "女性");
	set("age", 16);
	set("long","她是苗若兰的贴身侍婢。\n");
	set("attitude", "friendly");
	set("str", 15);
	set("int", 15);
	set("con", 19);
	set("dex", 17);
	set("per", 30);
	set("combat_exp", 1000);

	setup();
	carry_object(CLOTH_DIR"diaopi")->wear();
}
