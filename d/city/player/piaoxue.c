// piaoxue.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("飘雪", ({ "piaoxue"}));
	set("gender", "男性");
	set("class", "swordman");
	set("title", GRN"探花"NOR"武当派第三代弟子");
	set("nickname", HIC"飘"MAG"香"HIY"剑"HIG"雨"NOR);
	set("age", 16);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 26);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
