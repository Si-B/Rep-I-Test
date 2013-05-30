<?xml version="1.0" encoding="UTF-8"?>
<structure version="16" html-doctype="HTML4 Transitional" compatibility-view="IE9" relativeto="*SPS" encodinghtml="UTF-8" encodingrtf="ISO-8859-1" encodingpdf="UTF-8" useimportschema="0" embed-images="1" enable-authentic-scripts="1" authentic-scripts-in-debug-mode-external="0" generated-file-location="DEFAULT">
	<parameters/>
	<schemasources>
		<namespaces/>
		<schemasources>
			<xsdschemasource name="XML" main="1" schemafile="E:\Entwicklung\Java\HDB_Desk\Export\beanExport.xsd" workingxmlfile="E:\Entwicklung\Java\HDB_Desk\Export\beanExport.xml"/>
		</schemasources>
	</schemasources>
	<modules/>
	<flags>
		<scripts>
			<script language="javascript"/>
		</scripts>
		<mainparts/>
		<globalparts/>
		<designfragments/>
		<pagelayouts/>
		<xpath-functions/>
	</flags>
	<scripts>
		<script language="javascript"/>
	</scripts>
	<script-project>
		<Project version="2" app="AuthenticView"/>
	</script-project>
	<importedxslt/>
	<globalstyles/>
	<mainparts>
		<children>
			<globaltemplate subtype="main" match="/">
				<document-properties/>
				<styles font-family="Cordia New" table-layout="fixed"/>
				<children>
					<documentsection>
						<properties columncount="1" columngap="0.50in" headerfooterheight="variable" pagemultiplepages="0" pagenumberingformat="1" pagenumberingstartat="auto" pagestart="next" paperheight="8.27in" papermarginbottom="0.60in" papermarginfooter="0.30in" papermarginheader="0.30in" papermarginleft="0.79in" papermarginright="0.79in" papermargintop="0.60in" paperwidth="11.69in"/>
						<children>
							<globaltemplate subtype="pagelayout" match="headerall">
								<children>
									<tgrid>
										<styles font-family="Courier" width="100%"/>
										<children>
											<tgridbody-cols>
												<children>
													<tgridcol>
														<styles width="80%"/>
													</tgridcol>
													<tgridcol>
														<styles width="20%"/>
													</tgridcol>
												</children>
											</tgridbody-cols>
											<tgridbody-rows>
												<children>
													<tgridrow>
														<children>
															<tgridcell>
																<properties align="left"/>
																<styles font-size="10pt" padding="0"/>
																<children>
																	<text fixtext="Waffenabgang im Monat: ">
																		<styles font-weight="bold"/>
																	</text>
																	<template subtype="source" match="XML">
																		<variables/>
																	</template>
																</children>
															</tgridcell>
															<tgridcell>
																<properties align="right"/>
																<styles font-size="10pt" padding="0"/>
																<children>
																	<text fixtext="Seite: ">
																		<styles font-weight="bold"/>
																	</text>
																	<field/>
																	<text fixtext=" von "/>
																	<field type="pagetotal"/>
																	<text fixtext=" "/>
																</children>
															</tgridcell>
														</children>
													</tgridrow>
												</children>
											</tgridbody-rows>
										</children>
									</tgrid>
								</children>
							</globaltemplate>
							<globaltemplate subtype="pagelayout" match="footerall">
								<children>
									<tgrid>
										<styles font-family="Courier" width="100%"/>
										<children>
											<tgridbody-cols>
												<children>
													<tgridcol>
														<styles width="90%"/>
													</tgridcol>
													<tgridcol>
														<styles width="10%"/>
													</tgridcol>
												</children>
											</tgridbody-cols>
											<tgridbody-rows>
												<children>
													<tgridrow>
														<children>
															<tgridcell>
																<styles font-size="4pt" padding="0"/>
																<children>
																	<line>
																		<properties color="black" size="1"/>
																	</line>
																</children>
															</tgridcell>
															<tgridcell joinleft="1">
																<styles font-size="4pt"/>
															</tgridcell>
														</children>
													</tgridrow>
													<tgridrow>
														<children>
															<tgridcell>
																<properties align="left"/>
																<styles font-size="4pt" padding="0"/>
																<children>
																	<text fixtext="Condition Waffenhandelsbuch"/>
																</children>
															</tgridcell>
															<tgridcell>
																<properties align="right"/>
																<styles font-size="10pt" padding="0"/>
															</tgridcell>
														</children>
													</tgridrow>
												</children>
											</tgridbody-rows>
										</children>
									</tgrid>
								</children>
							</globaltemplate>
						</children>
					</documentsection>
					<tgrid>
						<properties border="0" dataformatas="plaintext" width="100%"/>
						<styles font-family="Courier" text-align="center" width="auto"/>
						<children>
							<tgridbody-cols>
								<children>
									<tgridcol>
										<styles width="10mm"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles text-align="center" width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
								</children>
							</tgridbody-cols>
							<tgridheader-rows>
								<styles background-color="#d2d2d2" font-size="5pt" font-weight="bold" white-space="pre-wrap"/>
								<children>
									<tgridrow>
										<styles height="auto"/>
										<children>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Lfd. ">
														<styles text-align="center"/>
													</text>
													<newline/>
													<text fixtext="Nummer">
														<styles text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Eingang">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Waffentyp">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Hersteller">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Seriennummer">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Überlasser">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Überlasser-adresse"/>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Abgang">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Empfänger">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Empfänger-adresse"/>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Nachweis">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Nachweisdatum">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Nachweisnummer">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
											<tgridcell>
												<styles border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" padding-bottom="1px" padding-left="2px" padding-right="2px" padding-top="1px" text-align="center" white-space="pre-wrap"/>
												<children>
													<text fixtext="Nachweisbehörde">
														<styles font-family="Courier" text-align="center"/>
													</text>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
								</children>
							</tgridheader-rows>
							<tgridbody-rows>
								<styles text-align="center"/>
								<children>
									<template subtype="source" match="XML">
										<children>
											<template subtype="element" match="waffen">
												<children>
													<template subtype="element" match="waffe">
														<children>
															<tgridrow>
																<properties _xbgcolor="if ( position() mod 2 = 0 ) then &quot;white&quot; else &quot;#e1e1e1&quot;"/>
																<styles _xtext-decoration="if (waffeStatus=&quot;Inaktiv&quot;) then &quot;line-through&quot; else &quot;none&quot;" font-size="7pt" text-align="center"/>
																<children>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="laufendeNummer">
																				<children>
																					<content subtype="regular">
																						<styles text-align="center"/>
																						<format basic-type="xsd" datatype="short"/>
																					</content>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="eingang">
																				<children>
																					<content subtype="regular">
																						<styles text-align="center"/>
																						<format basic-type="xsd" datatype="dateTime"/>
																					</content>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="waffentypFeingliederung">
																				<children>
																					<calltemplate subtype="named" match="LinebreakContent">
																						<parameters/>
																					</calltemplate>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="hersteller">
																				<children>
																					<calltemplate subtype="named" match="LinebreakContent">
																						<parameters/>
																					</calltemplate>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="seriennummer1">
																				<children>
																					<calltemplate subtype="named" match="LinebreakContent">
																						<parameters/>
																					</calltemplate>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="ueberlasser">
																				<children>
																					<content subtype="regular">
																						<styles text-align="center"/>
																						<format basic-type="xsd" datatype="short"/>
																					</content>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt"/>
																		<children>
																			<template subtype="element" match="ueberlasserAdresse">
																				<children>
																					<content subtype="regular">
																						<styles text-align="center"/>
																					</content>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="abgang">
																				<children>
																					<content subtype="regular">
																						<styles text-align="center"/>
																						<format basic-type="xsd" datatype="short"/>
																					</content>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="empfaenger">
																				<children>
																					<content subtype="regular">
																						<styles text-align="center"/>
																						<format basic-type="xsd" datatype="dateTime"/>
																					</content>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt"/>
																		<children>
																			<template subtype="element" match="empfaengerAdresse">
																				<children>
																					<content subtype="regular">
																						<styles text-align="center"/>
																					</content>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="nachweis">
																				<children>
																					<calltemplate subtype="named" match="LinebreakContent">
																						<parameters/>
																					</calltemplate>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="nachweisDatumAusstellung">
																				<children>
																					<calltemplate subtype="named" match="LinebreakContent">
																						<parameters/>
																					</calltemplate>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="nachweisNummer">
																				<children>
																					<calltemplate subtype="named" match="LinebreakContent">
																						<parameters/>
																					</calltemplate>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																	<tgridcell>
																		<styles font-size="5pt" keep-together="always" table-omit-header-at-break="true" text-align="center"/>
																		<children>
																			<template subtype="element" match="nachweisBehoerde">
																				<children>
																					<calltemplate subtype="named" match="LinebreakContent">
																						<parameters/>
																					</calltemplate>
																				</children>
																				<variables/>
																			</template>
																		</children>
																	</tgridcell>
																</children>
															</tgridrow>
														</children>
														<variables/>
													</template>
												</children>
												<variables/>
											</template>
										</children>
										<variables/>
									</template>
								</children>
							</tgridbody-rows>
						</children>
					</tgrid>
					<newline/>
				</children>
			</globaltemplate>
		</children>
	</mainparts>
	<globalparts/>
	<designfragments>
		<children>
			<globaltemplate subtype="named" match="LinebreakContent">
				<parameters/>
				<children>
					<autocalc xpath="string-join(for $i in 1 to string-length(.) return substring(.,$i,1),codepoints-to-string(8203))">
						<styles text-align="center"/>
					</autocalc>
				</children>
			</globaltemplate>
		</children>
	</designfragments>
	<xmltables/>
	<authentic-custom-toolbar-buttons/>
</structure>
