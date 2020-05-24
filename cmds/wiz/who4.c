// who4.c

#include <ansi.h>

int main()
{
	object *ob;
	string msg, fip;
	int i;
	seteuid( getuid() ); 

	ob = users();
	msg = "◎ 侠客行一百\n" + 
	"—————————————————————————————————————\n"
	+ "姓名          帐号          发呆   连线\n" +
	"—————————————————————————————————————\n";
/*	for(i=0; i<sizeof(ob); i++)
	{
		if( this_player() && !this_player()->visible(ob[i]) ) continue;
		msg += sprintf("%s%-14s%-14s%-7s%s\n",
			msg, ob[i]->query("name"), ob[i]->query("id"),
			query_idle(ob[i]) + "s", query_ip_name(ob[i]));
	}
	msg += "—————————————————————————————————————\n";
	this_player()->start_more(msg);
*/
	for(i=0; i<sizeof(ob); i++)
	{
		for(i=0; i<sizeof(ob); i++)
	{
		if( this_player() && !this_player()->visible(ob[i]) ) continue;
		if( ob[i]->query("balance")>1000000 )
		{ 
		msg += sprintf("%s%-14s%-14s%-7s%s\n",
			msg, ob[i]->query("name"), ob[i]->query("id"),
			query_idle(ob[i]) + "s", query_ip_name(ob[i]));
		}
	}
		msg += "—————————————————————————————————————\n";
		this_player()->start_more(msg);	
	}
	return 1;
}

