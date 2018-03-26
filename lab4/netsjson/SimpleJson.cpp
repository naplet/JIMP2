#include"SimpleJson.h"
#include <sstream>
#include <iomanip>

namespace nets{
    JsonValue::JsonValue(){
        theCase = 0;
    }

    JsonValue::~JsonValue() {

    }

    JsonValue::JsonValue(int value){
        theCase = 1;
        this->intX = value;
    }

    JsonValue::JsonValue(double value){
        theCase = 2;
        this->doubleX = value;
    }

    JsonValue::JsonValue(const std::string value){
        theCase = 3;
        this->stringX = value;
    }

    JsonValue::JsonValue(bool value){
        theCase = 4;
        this->boolX = value;
    }

    JsonValue::JsonValue(std::vector<JsonValue> values){
        theCase = 5;
        this->array = values;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> map){
        theCase = 6;
        this->map = map;
    }

    int JsonValue::GetTheCase() const {
        return theCase;
    }

    int JsonValue::GetIntX() const {
        return intX;
    }

    double JsonValue::GetDoubleX() const {
        return doubleX;
    }

    const std::string &JsonValue::GetStringX() const {
        return stringX;
    }

    bool JsonValue::GetBoolX() const {
        return boolX;
    }

    const std::vector<JsonValue> &JsonValue::GetArray() const {
        return array;
    }

    const std::map<std::string, JsonValue> &JsonValue::GetMap() const {
        return map;
    }

    std::string JsonValue::ToString() const{
        if(GetTheCase()==1)
            return std::to_string(GetIntX());
        else if(GetTheCase()==2){
            std::stringstream stringstream;
            stringstream << std::fixed << std::setprecision(2) << GetDoubleX();
            return stringstream.str();

        }
        else if(GetTheCase()==3)
        {
            return GetStringX();
        }
        else if(GetTheCase()==4){
            if(GetBoolX()==true){
                return "true";
            }
            else if(GetBoolX()==false){
                return "false";
            }
            else
                return "";

        }
        else if(GetTheCase()==5){
            std::string str = "[";
            bool first = true;
            for (auto const& value : GetArray()){
                if (!first) str+=", ";
                else first= false;
                str+=value.ToString();
            }
            str+="]";
            return str;
        }
        else if(GetTheCase()==6){
            std::string str = "[";
               for (auto const& value : GetMap()){
                std::string current = value.first;
                for (int i = 0; i<current.length();++i){
                    if (current[i] == '\"' || current[i] == '\\'){
                        current.insert(i,1,'\\');
                        ++i;
                    }
                }
                str+="\"" + current + "\": "+value.second.ToString()+", ";
            }
            str=str.substr(0,str.length()-2)+'}';
            return str;

        }
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        return GetMap().find("a")->second;

    }


}