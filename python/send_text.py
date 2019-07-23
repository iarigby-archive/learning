from twilio.rest import Client

# Your Account SID from twilio.com/console
account_sid = "AC616cd131b75fd7da498d087d34013273"
# Your Auth Token from twilio.com/console
auth_token  = "65fce3290af23a1af01730d492670c2d"

client = Client(account_sid, auth_token)

message = client.messages.create(
    to="+36702426935", 
    from_="+17172760130",
    body="Hello from Python!")

print(message.sid)
