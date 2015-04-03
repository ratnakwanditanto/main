#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace MyCalTestSuite {
	TEST_CLASS(DeleteCmdTest) {
	public:
        /*TEST_METHOD(TestDeleteByNum) {
            unsigned idToDel = 3;
            MockStorage::initMockStorage(TaskStub::getSampleTaskList());
            Task taskToDel = TaskStub::getTaskWithID(idToDel);



            MockStorage::cleanMockStorage();
        }*/
        
        TEST_METHOD(TestDeleteByName) {
            MockStorage::initMockStorage(TaskStub::getSmallTaskList());
            
            // TEST FOR ONE TASK REMAINING
            DeleteCmd delCmdObj;
            delCmdObj.prepareTaskId((unsigned) 3);
            UIObject oneRemaining = delCmdObj.execute();

            Assert::AreEqual(std::string("Remaining tasks for that day:"), oneRemaining.getHeaderText());

            TaskList actualTaskList;
            actualTaskList.loadTaskList(oneRemaining.getTaskList());
            Assert::AreEqual(TaskStub::getSampleTask1().toString() + "\n", actualTaskList.toString());

            // TEST FOR NO TASKS REMAINING
            delCmdObj.prepareTaskId((unsigned) 1);
            UIObject noneRemaining = delCmdObj.execute();

            Assert::AreEqual(std::string("No more tasks for that day!"), noneRemaining.getHeaderText());

            TaskList actualTaskList2;
            actualTaskList2.loadTaskList(noneRemaining.getTaskList());
            Assert::AreEqual(0, actualTaskList2.totalTasks());

            // check remaining tasks in storage
            Assert::AreEqual(std::string("5\ndummy T5\n1425986625\n1425990225\n0\n"), 
				StorageUtils::readFile("tasklist.txt"));

            MockStorage::cleanMockStorage();
        }

        /*
        TEST_METHOD(TestDeleteEmpty) {
            MockStorage::initMockStorage(TaskStub::getSampleTaskList());


            MockStorage::cleanMockStorage();
        }

        TEST_METHOD(TestDeleteNotFound) {
            MockStorage::initMockStorage(TaskStub::getSampleTaskList());


            MockStorage::cleanMockStorage();
        }

        TEST_METHOD(TestDeleteUndo) {
            MockStorage::initMockStorage(TaskStub::getSampleTaskList());


            MockStorage::cleanMockStorage();
        }*/
	};


}