package edu.handong.csee.java.finance;

public class Wallet {

      private boolean isOpening;
      private int amount;

      public int getAmount() {
           return amount;
      }

      public void insert(int amountToInesert) {
           if(isOpening != true) {
                System.out.println("Your wallet is closed. Now we open!");
                open();
           }

           amount = amount + amountToInesert;
      }

      public void takeOut(int amountToTakeOut) {
           if(isOpening != true) {
                System.out.println("Your wallet is closed. Now we open!");
                open();
            }

           if(amountToTakeOut > amount) {
                System.out.println("Not enough money in the Wallet");
                return;
           }
           amount = amount - amountToTakeOut;
      }

      public void open() {
           isOpening = true;
      }

      public void close() {
           isOpening = false;
      }

}
