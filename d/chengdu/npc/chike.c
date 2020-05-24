// Room: /d/chengdu/npc/chike.c 吃客
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("吃客", ({ "chike" }));
	set("gender", "男性");
	set("age", 20 + random(30));

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 750);
	set("shen_type", 1);

	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
	add_money("silver", 5);
}
