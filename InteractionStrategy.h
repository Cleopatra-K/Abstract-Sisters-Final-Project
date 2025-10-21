/* This is for how staff interact 
    is about how a staff member behaves when they interact with a customer.
    It controls the behaviour itself, not who handles the request.

    Chain of Responsibility (CoR) is for Who handles the request

In Our Code:
1. The request comes in via the InteractionMediator.
2. It passes the request to the CoR chain of Staff handlers.
3. The first staff member who can handle it, uses their Strategy to perform the behavior.
*/
