//
// FILE: dialoglelim.h -- Parameters for dominance elimination
//
// $Id$
//

#ifndef DIALOGELIM_H
#define DIALOGELIM_H

class dialogElim : public guiAutoDialog {
private:
  wxListBox *m_playerBox;
  wxCheckBox *m_allBox, *m_compressBox;
  wxRadioBox *m_domTypeBox, *m_domMethodBox, *m_domPrecisionBox;
  wxRadioBox *m_domConditionalBox;
  bool m_mixed;

  const char *HelpString(void) const { return ""; }
  
public:
  dialogElim(wxWindow *p_parent, const gArray<gText> &p_players, bool p_mixed);
  virtual ~dialogElim();

  gArray<int> Players(void) const;
  bool Compress(void) const { return m_compressBox->GetValue(); }

  bool FindAll(void) const { return m_allBox->GetValue(); }
  bool DomStrong(void) const { return (m_domTypeBox->GetSelection() == 1); }
  bool DomMixed(void) const { return (m_domMethodBox->GetSelection() == 1); }
  bool DomConditional(void) const
    { return (m_domConditionalBox->GetSelection() == 0); }
  gPrecision Precision(void) const
    { return (m_domPrecisionBox->GetSelection() == 0) ? precDOUBLE : precRATIONAL; }
};

#endif   // DIALOGELIM_H
