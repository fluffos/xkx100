// Room: /d/chengdu/npc/yuanseng.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("圆觉禅师", ({ "Yuan chanshi", "yuan", "chanshi" }));
	set("title","昭觉寺主持");
	set("long", "昭觉寺第九代主持，慈眉善目，雪白的长须挂在胸前。\n");
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 68);
	set("shen_type", 1);
	set("str", 26);
	set("int", 23);
	set("con", 29);
	set("dex", 19);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 18000);
	set("score", 1000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	setup();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
	carry_object(CLOTH_DIR"seng-shoe")->wear();
}

