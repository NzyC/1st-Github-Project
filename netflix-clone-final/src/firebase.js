import { initializeApp } from "firebase/app";
import { getFirestore} from 'firebase/firestore';
import { getAuth } from "firebase/auth";

const firebaseConfig = {
  apiKey: "AIzaSyAB3QmNZrPstI0FY90g-UaeDv_w3XqsA_I",
  authDomain: "netflix-clone-final-f42f2.firebaseapp.com",
  projectId: "netflix-clone-final-f42f2",
  storageBucket: "netflix-clone-final-f42f2.appspot.com",
  messagingSenderId: "982654452483",
  appId: "1:982654452483:web:8507bace510c487af59f36"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
export const auth = getAuth();
export const db = getFirestore();