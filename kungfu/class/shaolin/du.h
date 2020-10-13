// du.h for fight and apprentice to 3-du

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "灏戞灄娲�")
	{
		command("say " + RANK_D->query_respect(ob) + "涓庢湰娲剧礌鏃犳潵寰€锛屼笉鐭ユ�璇濅粠浣曡皥璧凤紵");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "灏戞灄娲�")
	{
		command("say " + RANK_D->query_respect(ob) + "鏄�織瀹跺紵瀛愶紝涓嶈兘鍦ㄥ�鍐呭�鑹恒€�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "锛岃传鍍у摢閲屾暍褰� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "鐨勫緬寮熸€庨航璺戝埌鎴戣繖鍎挎潵浜嗭紝鍝堝搱鍝� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("3du-ok")==1)
		{
			ob->delete_temp("3du-ok");

			if (ob->query_skill("dodge",1)>=120 &&
			ob->query_skill("force",1)>=120 &&
			ob->query_skill("parry",1)>=120 &&
			ob->query_skill("buddhism",1)>=120)
			{
			command("say 浣犺兘杩囬噾鍒氫紡榄斿湀锛屽搱鍝堝搱 !");
			command("say 璐�儳鍙堝緱涓€鍙��涔嬫墠锛岀湡鏄�彲鍠滃彲璐� !");

			name = ob->query("name");
			new_name = "鐜�" + name[2..3];
			ob->set("name", new_name);

			command("say 浠庝粖浠ュ悗浣犵殑娉曞悕鍙�仛" + new_name + "锛屾伃鍠滀綘鑽ｅ崌涓哄皯鏋楁淳鐜勫瓧杈堝紵瀛� !");
			command("recruit " + ob->query("id"));
			}
			else
			command("say 璐�儳瑕佹敹鐨勬槸鏈夌敤涔嬫墠锛屼綘杩樻槸鍥炲幓鍚戜綘甯堢埗瀛︿範鍚�!");
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "锛屾病鑳借繃閲戝垰浼忛瓟鍦堬紝鎴戜笉鎯虫敹浣犮€�");
			return;
		}
	}
	return;
}
