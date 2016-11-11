// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md
// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.
// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "Catch/include/catch.hpp"
#include "linked_list.h"
#include <random>

//=======================================================================
// Test cases
//=======================================================================



TEST_CASE( "Create an empty list" ) {
  Sorted_List l{};
  REQUIRE( l.is_empty() == true );
  REQUIRE( l.size() == 0 );
}


// Solve one TEST_CASE or WHEN at a time!
//
// Move this comment and following #if 0 down one case at a time!
// Make sure to close any open braces before this comment.
// The #if 0 will disable the rest of the file.
TEST_CASE( "Insert an item in an empty list" ) {
  Sorted_List l{};
  l.insert(5);
  REQUIRE( l.is_empty() == false );
  REQUIRE( l.size() == 1 );
}



SCENARIO( "Empty lists" ) {

  GIVEN( "An empty list" ) {
    Sorted_List l{};

    REQUIRE( l.is_empty() == true );
    REQUIRE( l.size() == 0 );

    WHEN( "an item is inserted" ) {
      // insert an item
      l.insert(5);
      THEN( "the size increase and the item is first in the list" ) {
        REQUIRE( l.is_empty() == false );
        REQUIRE( l.size() != 0 );
  //      REQUIRE( /* test that item is first in list */ );
        REQUIRE(l.is_first_on_list(5) == true);
      }
    }
    WHEN( "an item is removed" ) {
      // remove an ite
      l.remove(5);
      THEN( "the list is still empty" ) {
        // add your REQUIRE statements
        REQUIRE( l.is_empty() == true );
        REQUIRE( l.size() == 0 );
      }
    }

    WHEN( "the list is copied to a new list" ) {

      // copy your list to a new variable (copy constructor)
      Sorted_List l2{l};
      THEN( "the new list is also empty" ) {
        // add your REQUIRE statements
        REQUIRE( l2.is_empty() == true );
        REQUIRE( l2.size() == 0 );
      }
    }
  //}}

    WHEN( "the list is copied to an existing non-empty list" ) {
      // create and fill a list to act as the existing list
      Sorted_List l2{};
      l2.insert(5);
      l2.insert(2);
      l2.insert(3);
      // copy (assign) your empty list to the existing
      Sorted_List l1{};
      l2=l1;

      THEN( "the existing list is also empty" ) {
        // add your REQUIRE statements
        REQUIRE( l2.is_empty() == true );
        REQUIRE( l2.size() == 0 );
      }

    }
  }
}

SCENARIO( "Single item lists" ) {

  GIVEN( "A list with one item in it" ) {
    // create the given scenario
    Sorted_List l{};
    REQUIRE(l.is_empty() == true);
    WHEN( "a smaller item is inserted" ) {
      l.insert(2);
      REQUIRE(l.size() == 1);
      l.insert(3);
      REQUIRE(l.size() == 2);
      l.print_list();
      l.remove(2);
      l.remove(3);
      REQUIRE(l.size() == 0);
      l.insert(5);
      l.insert(4);

      THEN( /* describe what will happen */ "The list is sorted during the insert " ) {
        REQUIRE(l.size() == 2);
        l.print_list();
      }


    WHEN( "a larger item is inserted" ) {
      l.insert(7);
      //l.insert(9);
      /* describe what will happen */
      THEN(  "The list is sorted during the insert " ) {
        l.print_list();
        REQUIRE(l.size() == 3);
        cout<< "Size = "<<l.size();
      }
    }


    WHEN( "an item is removed" ) {

      THEN( /* describe what will happen */ "The list is sorted during the insert " ) {
          REQUIRE(l.size() == 2);
      }
    }
    WHEN( "the list is copied to a new list" ) {
      THEN( ""/* describe what will happen */ ) {
        Sorted_List l2{l};
        cout << "print list l2 copy" << endl;
        l2.print_list();
        cout << "print list l" << endl;
        l.print_list();
      }


    WHEN( "the list is copied to an existing non-empty list" ) {
      THEN( ""/* describe what will happen */ ) {
        Sorted_List l3{};
        Sorted_List l2{};
        l2.insert(333);
        l2.insert(555);

        l3.insert(3);
        l3.insert(4);
        l3.insert(23);
        l3.copylist(l2);
        //l3->head=copy(l2->head);
        REQUIRE(l2.size() == l3.size());


        //l3.copy(l2);
      }
    }
  }}}}
    #if 0

SCENARIO( "Multi-item lists" ) {

  GIVEN( "A list with five items in it" ) {

    // create the given scenario and all THEN statements
    // and all REQUIRE statements
    WHEN( "an item smaller than all other is inserted" ) {}
    WHEN( "an item larger than all other is inserted" ) {}
    WHEN( "an item smaller than all but one item is inserted" ) {}
    WHEN( "an item larger than all but one item is inserted" ) {}
    WHEN( "an item is removed" ) {}
    WHEN( "all items are removed" ) {}
    WHEN( "the list is copied to a new list" ) {}
    WHEN( "the list is copied to an existing non-empty list" ) {}
  }
}

SCENARIO( "Lists can be copied" ) {

  GIVEN( "A list with five items in it, and a new copy of that list" ) {

    WHEN( "the original list is changed" ) {
      THEN( "the copy remain unmodified" ) {
      }
    }

    WHEN( "the copied list is changed" ) {
      THEN( "the original remain unmodified" ) {
      }
    }
  }
}

SCENARIO( "Lists can be heavily used" ) {

  GIVEN( "A list with 1000 random items in it" ) {

    // create the given list with 1000 random items
    std::random_device random;
    std::uniform_int_distribution<int> uniform(1,1000);

    for (int i{0}; i < 1000; ++i)
    {
      int random = uniform(random); // generate a random number
      // insert into list
    }

    WHEN( "the list have 1000 random numbers inserted" ) {
      // THEN the list have 2000 items in correct order
      // (assumes unique inserts or duplicates allowed)
    }

    WHEN( "the list have 1000 random numbers removed" ) {
      // THEN the list is empty
      // (assumes successful removes)
    }
  }
}

Sorted_List trigger_move(Sorted_List l)
{
  // do some (any) modification to list
  return l;
}

SCENARIO( "Lists can be passed to functions" ) {

  GIVEN( "A list with 5 items in it" ) {

    Sorted_List given{};
    // insert 5 items

    WHEN( "the list is passed to trigger_move()" ) {

      Sorted_List l{ trigger_move(given) };

      THEN( "the given list remain and the result have the change" ) {
      }
    }
  }
}

// To really verify that your "important five" are called you should
// add cout-statements in each during development (comment out before
// demonstration).

// In addition you must of course verify that the list is printed
// correct and that no memory leaks occur during use. You can solve
// the printing part on your own. Here's how to run the (test) program
// when you check for memory leaks:
//
// $ valgrind --tool=memcheck a.out

// Finally you need to check that you can do all operations that make
// sens also on a immutable list (eg all operations but insert):
void use_const_list(Sorted_List const& l)
{
  // perform every operation that do not modify the list here
  return l;
}

#endif
