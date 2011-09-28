/* Copyright (C) 2011 Mobile Sorcery AB

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License, version 2, as published by
 the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 for more details.

 You should have received a copy of the GNU General Public License
 along with this program; see the file COPYING.  If not, write to the Free
 Software Foundation, 59 Temple Place - Suite 330, Boston, MA
 02111-1307, USA.
*/

#import <Foundation/Foundation.h>
#import <AddressBook/AddressBook.h>
#import "PimUtil.h"
#include "helpers/cpp_defs.h"
#include "helpers/cpp_ix_pim.h"
#include "PimContactItem.h"
#import "PimList.h"

@interface PimContactsList:  PimList {
    /**
     * Stores the contact items imported from address book or
     * created by user.
     */
    NSMutableDictionary* mContactsDictionary;

    /**
     * Reference to an object used to interact with the Address Book database.
     */
    ABAddressBookRef mAddressBook;

    /**
     * The current item index in key array(generated by mContactsDictionary).
     */
    int mKeysArrayIndex;
}

/**
 * Init function.
 */
-(id) init;

/**
 * Imports all contact items from Address Book.
 */
-(void) openList;

/**
 * Gets a handle to the next item in list.
 * @return A handle to the next item in list, or 0 if the are no more items,
 *         or one of the MA_PIM_ERR constants in case of error.
 */
-(MAHandle) getNextItem;

/**
 * Gets an pim item for a given handle.
 * @param itemHandle The specified handle.
 * @return The item, or nil if the database does not contain
 *         an item with the given handle.
 */
-(PimItem*) getItem:(MAHandle) itemHandle;

/**
 * Creates an Contact item.
 * @return A handle to the new Contact item.
 */
-(MAHandle) createItem;

/**
 * Closes the list.
 * Adds the new items into Address Book.
 * Saves the modified items into Address Book.
 * Removes all items from the list.
 * @return One of MA_PIM_ERR constants.
 */
-(int) close;

/**
 * Closes a given item.
 * @param itemHandle A handle to a pim item.
 * @return One of the MA_PIM_ERR constants.
 */
-(int) closeItem:(MAHandle) itemHandle;

/**
 * Adds an item in Address Book.
 * @param item The given item.
 * @return One of the MA_PIM_ERR constants.
 */
-(int) saveItemInAddressBook:(PimContactItem*) item;

/**
 * Removes an pim item from this list.
 * @param itemHandle The given item.
 * @return One of the MA_PIM_ERR constants.
 **/
-(int) removeItem:(MAHandle) itemHandle;

@end
