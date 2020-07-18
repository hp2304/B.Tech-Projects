package com.resumeBuilder.controller.company;

import com.resumeBuilder.model.company.Company;

import java.util.ArrayList;

public abstract class FindCompany {

    public static Company findCompanyName(ArrayList<Company> companies, String userName) {
        for (Company temp : companies) {
            if (temp.getComUserName().equals(userName)) {
                return temp;
            }
        }
        return null;
    }

    public static Company findCompany(ArrayList<Company> companies, String userName, String passWord) {

        for (Company temp : companies) {
            if (temp.getComUserName().equals(userName) && temp.getComPassWord().equals(passWord)) {
                return temp;
            }
        }
        return null;
    }
}