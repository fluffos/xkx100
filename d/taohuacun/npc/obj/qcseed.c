
inherit __DIR__"seed.c";

void  create()
{
	::create();
	set_name( "青菜种", ({"qingcai seed","seed","zhongzi"}));
	set("value", 100 );
}