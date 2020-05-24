// ji.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("季镖头", ({ "ji biaotou", "ji" }));
	set("title", HIR"福"HIC"威"YEL"镖局"HIY"镖头"NOR);
	set("gender", "男性");
	set("age", 35);

	set("combat_exp", 5000);
	set("shen_type", 1);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
