// walker.c

inherit NPC;

void create()
{
        set_name("路人", ({ "walker" }) );
        set("gender", "男性" );
        set("age", 45);
        set("str", 16);
        set("con", 24);
        set("dex", 21);
        set("per", 17);
        set("int", 14);
        set("attitude", "friendly");
        set("combat_exp", 500);

        setup();

        carry_object("/d/wanjiegu/npc/obj/cloth")->wear();
}

