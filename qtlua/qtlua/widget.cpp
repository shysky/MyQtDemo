#include "widget.h"
#include "ctest.h"
#include "luaengine.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    LuaBClass::Register();
    LuaCTest::Register();
    LuaEngine *le = LuaEngine::getInstance();

    le->dofile("test.lua");

    exit(0);
}

Widget::~Widget()
{
    LuaEngine::getInstance()->closeState();
}
