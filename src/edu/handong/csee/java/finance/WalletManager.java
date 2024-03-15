package edu.handong.csee.java.finance;

public class WalletManager {

      private boolean isActive;
      private String name;
      private String gender;
      private Wallet myWallet;

      public void setName(String managerName) {
           name = managerName;
      }

      public Wallet getWallet() {
          return myWallet;
      }


      public void setWallet(Wallet wallet) {
          myWallet = wallet;
      }

      public void checkMyAmount() {
            System.out.println(name + " has " + myWallet.getAmount() + " now !");
       }


      public String getName() {
           return name;
      }

      public void setGender(String managerGener) {
           gender = managerGener;
      }

      public String getGender() {
           return gender;
      }

      public void active() {
           isActive= true;
      }
      public void inactive() {
        isActive= false;
   }
}
