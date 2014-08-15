# BTTB - Better Than That Tennisball 
  
Sonar-fed LED indicator showing how far from the wall I am when parking my car. The problem is usually solved by hanging a tennis ball in a piece of string so it touches the windscreen when the front of the car is at a perfect distance from the wall while still making it possible to close the garage door.
(see http://lifehacker.com/5841166/penetrate-your-garage-safely-and-park-better-with-some-string-and-a-tennis-ball)
  
I solved it this way since I'm not some cave man.
  
Every 3 seconds a ping is sent if the circuit is passive. If no reply is recieved or the same reply is recieved over and over again nothing happens. If the distance changes the circuit will go into an active mode where pings are sent every .5 seconds. An RGB-led will change from green to red as the object (car) nears the wall. If the object (car) gets closer than a certain value the LED starts flashing red. If the same distance is reported for 10 seconds the circuit switches back to passive mode.