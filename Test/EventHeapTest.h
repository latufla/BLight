#pragma once

#include "stdafx.h"
#include "EventHeap.h"

class EventHeapTest : public ::testing::Test{
};

EventHeap<ObjectBase, ViewBase>* heap = &EventHeap<ObjectBase, ViewBase>::getInstance();

TEST_F(EventHeapTest, AddListener) 
{
	ObjectBase* obj = new ObjectBase(1, "obj1");
	ViewBase* view = new ViewBase();
	heap->registerObject(obj, view, &ViewBase::update);
	
	ASSERT_TRUE(heap->events[0].invoker == obj);
	ASSERT_TRUE(heap->events[0].reciever == view);
	ASSERT_TRUE(heap->events[0].listener == &ViewBase::update);
	ASSERT_TRUE(heap->events[0].typeId == CHANGE);

	heap->unregisterObject(obj);
	delete obj;
	delete view;
}

TEST_F(EventHeapTest, RemoveListener) 
{
	ObjectBase* obj = new ObjectBase(1, "obj1");
	ViewBase* view = new ViewBase();
	heap->registerObject(obj, view, &ViewBase::update);
	ASSERT_TRUE(heap->events.size() == 1);
	
	heap->unregisterObject(obj);
	ASSERT_TRUE(heap->events.size() == 0);
}

TEST_F(EventHeapTest, Add2ListenersOfSameInvoker) 
{
	ObjectBase* obj = new ObjectBase(1, "obj1");
	ViewBase* view = new ViewBase();
	ViewBase* view2 = new ViewBase();

	heap->registerObject(obj, view, &ViewBase::update);
	heap->registerObject(obj, view2, &ViewBase::update);
	
	ASSERT_TRUE(heap->events[0].invoker == obj);
	ASSERT_TRUE(heap->events[0].reciever == view);
	ASSERT_TRUE(heap->events[1].invoker == obj);
	ASSERT_TRUE(heap->events[1].reciever == view2);

	ASSERT_TRUE(heap->events.size() == 2);
	heap->unregisterObject(obj);
	delete obj;
	delete view;
	delete view2;
}

TEST_F(EventHeapTest, Remove2ListenersOfSameInvoker) 
{
	ObjectBase* obj = new ObjectBase(1, "obj1");
	ViewBase* view = new ViewBase();
	ViewBase* view2 = new ViewBase();

	heap->registerObject(obj, view, &ViewBase::update);
	heap->registerObject(obj, view2, &ViewBase::update);
	heap->unregisterObject(obj);
	ASSERT_TRUE(heap->events.size() == 0);
	
	delete obj;
	delete view;
	delete view2;
}

TEST_F(EventHeapTest, Remove2ListenersOfSameInvokerWhenHasAnotherInvokerListeners) 
{
	ObjectBase* obj = new ObjectBase(1, "obj1");
	ObjectBase* obj2 = new ObjectBase(2, "obj2");
	ViewBase* view = new ViewBase();
	ViewBase* view2 = new ViewBase();
	
	heap->registerObject(obj, view, &ViewBase::update);
	heap->registerObject(obj2, view, &ViewBase::update);
	heap->registerObject(obj, view2, &ViewBase::update);
	heap->unregisterObject(obj);

	ASSERT_TRUE(heap->events.size() == 1);
	ASSERT_TRUE(heap->events[0].invoker == obj2);

	delete obj;
	delete obj2;
	delete view;
	delete view2;
}



