#include "JsonConnector.h"

ObjectInfo* JsonConnector::createInfoFromJson(FILE* file)
{
	if(file != nullptr){
		rapidjson::FileStream is(file);
		rapidjson::Document d;
		if(!d.ParseStream<0>(is).HasParseError()){
			printf("%s\n", d["hello"].GetString());
			printf("%s\n", d["bye"].GetString());

			rapidjson::Value& a = d["a"];
			rapidjson::SizeType id = 1;
			if(d["a"].IsArray()){
				printf("a[%d] = %d\n", id, a[id].GetInt());
			}
		}
	}
	return nullptr;
}
