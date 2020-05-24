// yunyan.c
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;

void create()
{
	set_name("谢云烟", ({ "xie yunyan", "xie", "yunyan" }));
	set("long", "她面容娇媚，皮肤光滑白嫩，一双黑眸顾盼留情，明目善睐。\n");
	set("title", "千娇百媚");
	set("gender", "女性");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();
	carry_object("/d/city/obj/necklace")->wear();
	carry_object("/d/city/obj/pink_cloth")->wear();
	carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/city/obj/goldring")->wear();
}

