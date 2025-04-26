# Uber 🚕

The *"Uber"* project represents a simplified taxi company system that supports two types of users: customers and drivers. Users can register and log in using a username and password.    
Upon registration, the system checks if a user with the same username already exists. If not, the user can proceed; otherwise, they will be prompted to choose a new username.     
Upon launching the program, two files named *"clients"* and *"drivers"* must be present for the system to read the necessary information and save updates.    
If these files are missing, the program cannot read or save any changes.

## Customer Actions:

1. **Order a Taxi**  
   The customer provides the number of passengers, current address, and coordinates, with an optional field for additional information. Then, the customer inputs the final destination and its coordinates.    
The order is sent to the nearest available driver. If the driver refuses, the order is forwarded to the next closest driver.    
If no driver accepts the order, it is canceled, and the customer receives a suitable message. The customer can only have one active order at a time.    
If they wish to change it, they must cancel the previous one and create a new order.

3. **Check Order**  
   After placing an order, the status remains in waiting. If the customer checks the order before it's accepted, a message saying *"Your order is not accepted yet!"* will be shown.    
If the order is accepted, the driver's details (name, surname, car number, phone number, and rating) along with the estimated arrival time are displayed.

5. **Cancel Order**  
   Customers can cancel an order. If the order is already accepted by a driver, a message will be sent to the driver, and the order is canceled, releasing the driver from the task.

6. **Pay for Order**  
   After the order is completed, the customer is required to pay, but only after the driver marks the order as completed. If the customer tries to make a new order without paying for the previous one, a message *"There is an order you need to pay for first!"* will be shown. If the order has not been marked as completed, the message *"You must wait for the driver to assure the order is finished."* will be displayed. After payment, the customer can rate the driver with a score between 1 and 5. If the customer doesn’t want to rate, the program continues as usual.

7. **Add Funds to Account**  
   The customer can add money to their account. For simplicity, it's assumed that a valid credit or debit card is used, with no further checks needed.

8. **View Profile**  
   Displays the customer's profile details.

9. **Show My Messages**  
   Displays messages for the customer, which are deleted upon logging out.

## Driver Actions:

1. **Change Address**  
   Drivers can change their current address and coordinates by entering the new address and its corresponding coordinates.

2. **Check Orders**  
   Drivers can view all orders sent to them, including the order ID, the customer's details, and both the starting and final destinations with their coordinates.

3. **Accept Order**  
   Drivers can accept an order by entering the order ID. Once accepted, no further orders can be accepted. After accepting an order, the driver must enter the estimated time to reach the destination.

4. **Reject Order**  
   Drivers can reject an order by entering the order ID. The rejected order will be removed from their list and sent to the next closest driver.

5. **Complete Order**  
   Marks the accepted order as completed, allowing the customer to pay and freeing the driver from the task.

6. **View Profile**  
   Displays the driver's profile details.

7. **Show My Messages**  
   Displays the driver's messages, which are deleted upon logging out.
