import cv2
face_cascade =cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
img = cv2.imread("path of your image")
faces = face_cascade.detectMultiScale(img,scaleFactor=1.05,minNeighbors=5)
print(type(faces))
print(faces)

for x,y,w,h in faces:
    #img = cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,255),2)
    img = cv2.circle(img,(int(x+w/2),int(y+h/2)),int(w/1.4),(255,0,255),thickness=3)
resize = cv2.resize(img,(int(img.shape[1]/3),int(img.shape[0]/3)))
cv2.imshow("img",resize)
cv2.waitKey()
cv2.destroyAllWindows()