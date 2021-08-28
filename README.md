# Shopping-Portal
![Shopping Cart]("D:\G & G\Shopping Portal\images\Shopping Portal.png " "Shopping Cart")
___
#### (In C++ using OOP conceps and Double Linked List concepts)
![C++ Logo]("D:\G & G\Shopping Portal\images\c++ logo" "C++ Logo")
___
```java
        Overview/Abstract
```
The online shopping system presents an online display of an order cut off time and an associated delivery window for items selected by the customer. The system accepts the customer's submission of a purchase order for the item in response to a time of submission being before the order cut off time. The online shopping system does not settle with a credit supplier of the customer until the item selected by the customer is picked from inventory but before it is delivered. Therefore, the customer can go online and make changes to the order. In addition, available service windows are presented to the customer as a function of customer selected order and service types and further, the order picking is assigned in accordance with a picker's preference.
When ordering goods, many shopping systems provide a virtual shopping cart for holding items selected for purchase. Successive items selected for purchase are placed into the virtual shopping cart until a customer completes their shopping trip. Virtual shopping carts may be examined at any time, and their contents can be edited or deleted at the option of the customer. Once the customer decides to submit a purchase order, the customer may print the contents of the virtual shopping basket in order to obtain a hard copy record of the transaction.

___
```java
            Implementation
```
With time complexity and dynamic nature of various operations in shopping portal in mind, we decided to implement it using Double linked list data structure using the concept of Object Oriented Programming and also Applying Recursion for Real time Implementation to keep track of Every Products in the shop, Every Customer Visited the shop and Applying Respective Operations on them.
___

In this project, there are two major sections:

**1->** <p>First is The Administrator portal wherein admin will be allowed to add, access, modify product details, View the list of Product currently available in the shop and the customers visited the shop. Basically, the Admin can do pretty much everything. We used Object of Product Class to store Information about Every Product separately and linked them with Double Linked List. The Product details include ProductName, Productid, Quantity of that Product Available Currently, and Product Price (per Kg/lit/item, etc.).</p>

Following Diagram shows product class and its operations: 
![Product class]("D:\G & G\Shopping Portal\images\product.png "Product Class")
![Product Operations Class]("D:\G & G\Shopping Portal "Product Operations Class")
___
**2->** <p>Second, we have Customer portal. As and when the Customer enters the shop his details are asked which include Customer name, Mobile Number and Address and we are Dynamically Generating Unique Id for Each Customer Visited the Shop. Also, a trolley of Product Type is assigned to the Customer which is used to store the products purchased by the Customers. Customer can select Various products available in the market and after the selection of all the items, bill is generated and after successful payment of purchased items, record of product quantities available in the shop is updated. Also, the copy of same including customer’s personal details is stored in database for future reference.</p>

Following Diagram shows Customer class and its operations:
![Customer class]("D:\G & G\Shopping Portal\images\product.png "Customer Class")
![Customer Operations Class]("D:\G & G\Shopping Portal\images\product operations.png "Customer Operations Class")
___

## Screenshots

![Customer Portal]("D:\G & G\Shopping Portal\images\cusotmer portal.png" "Customer side of the protal where he/she can buy/add items to his/her trolley and generate bill")
###### *how portal looks from cutomers' side*

![Customer Portal]("D:\G & G\Shopping Portal\images\Assigning Trolley To the customer.png" "Customer Trolley Assigned")
###### *how Trolley looks cutomers'*



![Customer Portal]("D:\G & G\Shopping Portal\images\Administrator portal" "Administration side of the portal")
###### *Adminitration side of the portal where he/she can add/remove items from the list and much more*



![Customer Portal]("D:\G & G\Shopping Portal\images\Adding items to the list.png" "showing the list of items present")
###### *list of items to purchase from*




