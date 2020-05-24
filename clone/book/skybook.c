// skybook.c

#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
void create()
{
	set_name(HIB"无字天书"NOR, ({"skybook","book"}) );
	set_weight(10);
	set("no_steal", 1);
	set("no_beg", 1);
//	set("no_get", 1);
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
	if (!present(this_object(), this_player())) return 0;

	tell_object(me,
    "法诀		    功能
筋斗云(cloud)	 到想去的地方\n");
	return 1;
}
// 筋斗云

int cloud_goto(string arg)
{
	object obj,mme=this_player();
	object* ob;
	int i;
	ob = users();

	if (!present(this_object(), this_player()))
		return 0;

	for ( i=sizeof(ob); i>0; i-- )
	{
		if ((ob[i-1]->query("id")==arg) && ( !wizardp(ob[i-1])))
		{
			obj = environment(ob[i-1]);
			this_player()->move(obj);
			tell_object(mme,HIM"你一个筋斗窜向空中,只见眼前红云飞过,耳边风呼呼作响 ..\n\n"NOR);
			tell_object(mme,"哇喔,好痛快,好爽,爽歪歪!\n\n");
			mme->move(obj);
			tell_object(mme,"你驾着云缓缓下降,叭叽一声,嘿!安全着陆...\n");
			return 1;
		}
	}
	return 0;
}

void owner_is_killed()
{
	write(HIY"只见眼前金光一闪...好象是.....\n"NOR);
	destruct(this_object());
}
