// skybook.c

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;


void create()
{
	set_name(HIY"无字天书"NOR, ({"skybook","book"}) );
	set_weight(10);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_get", 1);
	set("no_drop","哇？天书都想丢掉,小心遭天谴。\n\n");
	set("long",@LONG
此乃当年仙人赠于"蛋生"的宝物,因为蛋生不识字,仙人施了法,
把天书变成了无字天书,呵呵!就是文盲也能读懂,快看看(kan)吧！
LONG );
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("material", "unknow");
	}
}

void init()
{
	add_action( "kan_book", "kanbook" );
	add_action( "bigu_eat", "bigu" );
	add_action( "cloud_goto", "cloud");
}

int query_autoload()
{
	return 1;
}

//介绍
int kan_book()
{
	object me;
	me=this_player();
	if (!present(this_object(), this_player()))
		return 0;

	tell_object(me,
    "法诀		    功能

辟谷(bigu)        三天三夜不吃不喝\n

康复(body)        立马恢复精神体力\n

筋斗云(cloud)     到想去的地方\n");
	return 1;
}

// 辟谷

int bigu_eat()
{
	object  ob, me;
	int	     fw;

	ob = this_object();
	me = this_player();

	if (!present(this_object(), this_player()))
		return 0;

	if( !me->query_condition("f_condi") )
	{
		write(HIY"你口中念念有词,那咦咪哞嘻...\n"NOR);
		tell_object(me, "你只觉神清气爽,可以不吃饭了...\n" );

		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);

		write("三天三夜也不会饿了！\n\n");
		me->apply_condition("f_condi", 5);
		ob->set("eated", "xixi");
	}
	else
	{

		tell_object(me, "Ou。。你打了个饱嗝。。。Ou...Ou...\n" );

		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);
	}

	return 1;
}
// 筋斗云

int cloud_goto(string arg)
{
	string home;
	object mme;
	int goto_inventory = 0;
	object obj;
	string msg;
	mme=this_player();
	if (!present(this_object(), this_player()))
		return 0;

	if( !arg ) return notify_fail("你要去哪里？\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if( !arg ) return notify_fail("你要去哪里？\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !mme->visible(obj)) {
		arg = resolve_path(mme->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return mme->move(arg);
			return notify_fail("没有这个玩家、生物、或地方。\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");
	tell_object(mme,HIM"你一个筋斗窜向空中,只见眼前红云飞过,耳边风呼呼作响 .
.\n\n"NOR);
	tell_object(mme,"哇喔,好痛快,好爽,爽歪歪!\n\n");
	mme->move(obj);

	tell_object(mme,"你驾着云缓缓下降,叭叽一声,嘿!安全着陆...\n");
	return 1;
}
// 恢复
int body_recover()
{
    object mme;
    mme=this_player();
    mme->set("jing",mme->query("max_jing"));
    mme->set("eff_jing",mme->query("max_jing"));
    mme->set("qi",mme->query("max_qi"));
    mme->set("eff_qi",mme->query("max_qi"));
    mme->set("neili",mme->query("max_neili"));
    tell_object(mme,"哇喔,太好了,你觉得全身都是力量!\n");
    return 1;
}
void owner_is_killed() {

	write(HIY"只见眼前金光一闪...好象是.....\n"NOR);
	destruct(this_object());
}
