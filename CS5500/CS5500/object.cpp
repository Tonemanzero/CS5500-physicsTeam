#include "object.h"
#include <string>
#include <vector>
using namespace std;

//templateObject functions

templateObject::templateObject(string nam="void", int i=0, int hp=0, int str=0, int wei=0, bool isFire=0, bool isWet=0)
{
    name=nam;
    id=i;
    baseHp=hp;
    strength=str;
    weight=wei;
    isFlamable=isFire;
    isWetable=isWet;
}
string templateObject::getName()
{
    return name;
}
int templateObject::getId()
{
    return id;
}
int templateObject::getHp()
{
    return baseHp;
}
int templateObject::getStrength()
{
    return strength;
}
int templateObject::getWeight()
{
    return weight;
}
bool templateObject::getIsFlamable()
{
    return isFlamable;
}
bool templateObject::getIsWetable()
{
    return isWetable;
}


//templateObjectList functions

templateObjectList::templateObjectList()
{
    list.resize(0);
    size=0;
}
int templateObjectList::getSize()
{
    return size;
}
int templateObjectList::addTemplate(templateObject temp)
{
    list.push_back(temp);
    size += 1;
    return size-1;
}
int templateObjectList::addTemplate(string name,int hp=0,int strength=0,int weight=0,bool isFlamable=0,bool isWetable=0)
{
    templateObject temp(name,size,hp,strength,weight,isFlamable,isWetable);
    list.push_back(temp);
    size += 1;
    return size-1;
}
templateObject templateObjectList::getTemplate(int i)
{
    if(i<size)
        return list[i];
    else
    {
        templateObject nell("null",-1);
        return nell;
    }
}
int templateObjectList::findTemplate(string name)
{
    for(int i=0;i<size;i++)
    {
        if(name==list[i].getName())
            return i;
    }
    return -1;
}

//object functions
object::object()
{
    id = 0;
    hp = 0;
    strength = 0;
    weight = 0;
    stateFire = false;
    stateWet = false;
}
object::object(int i=0,int h=0,int str=0,int wei=0,bool isfire=0,bool iswet=0)
{
    id = i;
    hp = h;
    strength = str;
    weight = wei;
    stateFire = isfire;
    stateWet = iswet;
}
object::object(templateObject temp)
{
    id = temp.getId();
    hp = temp.getHp();
    strength = temp.getStrength();
    weight = temp.getWeight();
    stateFire = 0;
    stateWet = 0;
}
object::object(templateObjectList list,int i)
{
    templateObject temp = list.getTemplate(i);
    id = temp.getId();
    hp = temp.getHp();
    strength = temp.getStrength();
    weight = temp.getWeight();
    stateFire = 0;
    stateWet = 0;
}
    int object::getId()
    {
        return id;
    }
    int object::getHp()
    {
        return hp;
    }
    int object::getStrength()
    {
        return strength;
    }
    int object::getWeight()
    {
        return weight;
    }
    bool object::getStateFire()
    {
        return stateFire;
    }
    bool object::getStateWet()
    {
        return stateWet;
    }
   
    void object::setHp(int i)
    {
        hp = i;
    }
    void object::setStrength(int i)
    {
        strength = i;
    }
    void object::setWeight(int i)
    {
        weight = i;
    }
    void object::setStateFire(bool i)
    {
        stateFire = i;
    }
    void object::setStateWet(bool i)
    {
        stateWet = i;
    }