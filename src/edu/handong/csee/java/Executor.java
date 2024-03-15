package edu.handong.csee.java;

import edu.handong.csee.java.finance.Wallet;
import edu.handong.csee.java.finance.WalletManager;

public class Executor {

	public static void main(String[] args) {

		Executor myExecutor = new Executor();

		myExecutor.run(args);

	}

	public void run(String[] args) {
		WalletManager jc = new WalletManager();
                  jc.setName("JC Nam");
		WalletManager jh = new WalletManager();
		jh.setName("JH Park");



		Wallet jcWallet = new Wallet();
		Wallet jhWallet = new Wallet();

		jcWallet.insert(Integer.parseInt(args[0]));
jhWallet.insert(Integer.parseInt(args[1]));
		
jc.setWallet(jcWallet);
jh.setWallet(jhWallet);

jcWallet.insert(1000);		//insert로 바꿔야 돌아감..Not Wallet
jhWallet.insert(2000);

jc.checkMyAmount();
jh.checkMyAmount();
	}
}
