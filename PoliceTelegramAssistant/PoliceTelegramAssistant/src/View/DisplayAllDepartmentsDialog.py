#!/usr/bin/env python
#coding=utf-8

from ViewBase import DisplayAllDepartmentsDialogBase

class DisplayAllDepartmentsDialog(DisplayAllDepartmentsDialogBase):
    def __init__(self, parent, selected):
        DisplayAllDepartmentsDialogBase.__init__(self, parent)
        self.listSelectedDepartment = selected
        self.FillSelectedListBoxFromListDepartment(self.listSelectedDepartment)

    def OnAddButtonClick(self, event):
        listAllSelectedItemId = self.treeCtrl_AllDepartments.GetSelections()
        for itemId in listAllSelectedItemId:
            itemData = self.treeCtrl_AllDepartments.GetItemData(itemId)
            data = itemData.GetData()
            self.DepartmentListUniqueAppend(self.listSelectedDepartment, data)

        self.FillSelectedListBoxFromListDepartment(self.listSelectedDepartment)


    def OnRemoveButtonClick( self, event ):
        tupleSelected = self.listBox_Selected.GetSelections()
        for i in tupleSelected:
            self.listSelectedDepartment.remove(self.listSelectedDepartment[i])

        self.FillSelectedListBoxFromListDepartment(self.listSelectedDepartment)

    def OnButtonOKClick( self, event ):
        self.EndModal(0)
    
    def OnButtonResetClick( self, event ):
        del self.listSelectedDepartment[0:len(self.listSelectedDepartment)]
        self.FillSelectedListBoxFromListDepartment(self.listSelectedDepartment)


    def OnDialogClose( self, event ):
        self.EndModal(0)


    def DepartmentListUniqueAppend(self, _list_, _item):
        for item in _list_:
            if item.m_Id == _item.m_Id:
                return False
        _list_.append(_item)
        return True


    def FillSelectedListBoxFromListDepartment(self, _listDepartment):
        listSelected = []
        for item in _listDepartment:
            listSelected.append(item.m_Name)

        self.listBox_Selected.Set(listSelected)
