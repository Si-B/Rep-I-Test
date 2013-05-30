<?xml version="1.0" encoding="UTF-8"?>
<structure version="15" html-doctype="HTML4 Transitional" compatibility-view="IE9" relativeto="*SPS" encodinghtml="UTF-8" encodingrtf="ISO-8859-1" encodingpdf="UTF-8" useimportschema="0" embed-images="1" ShowDesignMarkups="2" enable-authentic-scripts="1" authentic-scripts-in-debug-mode-external="0" generated-file-location="DEFAULT">
	<parameters/>
	<schemasources>
		<namespaces/>
		<schemasources>
			<xsdschemasource name="XML" main="1" schemafile="beanExport.xsd" workingxmlfile="beanExport.xml"/>
		</schemasources>
	</schemasources>
	<modules/>
	<flags>
		<scripts/>
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
				<styles table-layout="fixed"/>
				<children>
					<documentsection>
						<properties columncount="1" columngap="1cm" headerfooterheight="fixed" pagemultiplepages="0" pagenumberingformat="1" pagenumberingstartat="auto" pagestart="next" paperheight="29.70cm" papermarginbottom="2.01cm" papermarginfooter="0.76cm" papermarginheader="0.76cm" papermarginleft="1.52cm" papermarginright="1.52cm" papermargintop="2.01cm" paperwidth="21cm"/>
						<children>
							<globaltemplate subtype="pagelayout" match="headerall">
								<children>
									<tgrid>
										<styles font-family="Courier" font-weight="bold" width="100%"/>
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
																<styles font-size="11pt" padding="0"/>
																<children>
																	<text fixtext="Waffe: "/>
																	<template subtype="source" match="XML">
																		<children>
																			<template subtype="element" match="waffen">
																				<children>
																					<template subtype="element" match="waffe">
																						<children>
																							<template subtype="element" match="seriennummer1">
																								<children>
																									<content/>
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
																		<variables/>
																	</template>
																	<text fixtext=", Lfd. Nummer: "/>
																	<template subtype="source" match="XML">
																		<children>
																			<template subtype="element" match="waffen">
																				<children>
																					<template subtype="element" match="waffe">
																						<children>
																							<template subtype="element" match="laufendeNummer">
																								<children>
																									<content>
																										<format basic-type="xsd" datatype="short"/>
																									</content>
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
																		<variables/>
																	</template>
																	<text fixtext=" - Lieferschein"/>
																</children>
															</tgridcell>
															<tgridcell>
																<properties align="right"/>
																<styles font-size="11pt" padding="0" text-align="right"/>
																<children>
																	<autocalc xpath="current-date()">
																		<format basic-type="xsd" string="DD. MM. YYYY" datatype="date"/>
																	</autocalc>
																</children>
															</tgridcell>
														</children>
													</tgridrow>
													<tgridrow>
														<children>
															<tgridcell>
																<styles padding="0"/>
																<children>
																	<line>
																		<properties color="black" size="1"/>
																	</line>
																</children>
															</tgridcell>
															<tgridcell joinleft="1">
																<styles text-align="right"/>
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
										<styles width="100%"/>
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
																<styles font-family="Courier" padding="0"/>
																<children>
																	<line>
																		<properties color="black" size="1"/>
																	</line>
																</children>
															</tgridcell>
															<tgridcell joinleft="1">
																<styles font-family="Courier"/>
															</tgridcell>
														</children>
													</tgridrow>
													<tgridrow>
														<children>
															<tgridcell>
																<properties align="left"/>
																<styles font-family="Courier" font-size="10pt" padding="0"/>
																<children>
																	<text fixtext="Condition Waffenhandelsbuch"/>
																</children>
															</tgridcell>
															<tgridcell>
																<properties align="right"/>
																<styles font-family="Courier" font-size="10pt" padding="0"/>
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
						<properties border="0" cellpadding="1" cellspacing="1"/>
						<styles font-family="Courier"/>
						<children>
							<tgridbody-cols>
								<children>
									<tgridcol>
										<styles width="7.43cm"/>
									</tgridcol>
									<tgridcol>
										<styles width="auto"/>
									</tgridcol>
								</children>
							</tgridbody-cols>
							<tgridbody-rows>
								<children>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Empfänger"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="empfaenger">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Empfängeradresse"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="empfaengerAdresse">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Lfd. Nummer"/>
													<newline/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="laufendeNummer">
																				<children>
																					<content>
																						<format basic-type="xsd" datatype="short"/>
																					</content>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Waffentypfeingliederung"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="waffentypFeingliederung">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Hersteller"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="hersteller">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Kaliber"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="kaliber">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Seriennumer"/>
													<newline/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="seriennummer1">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<styles height="0.42cm"/>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Abgang"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="abgang">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Nachweis"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="nachweis">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Nachweisnummer"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="nachweisNummer">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Nachweisdatum"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="nachweisDatum">
																				<children>
																					<content/>
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
														<variables/>
													</template>
												</children>
											</tgridcell>
										</children>
									</tgridrow>
									<tgridrow>
										<styles height="0.42cm"/>
										<children>
											<tgridcell>
												<styles font-weight="bold"/>
												<children>
													<text fixtext="Nachweisbehörde"/>
												</children>
											</tgridcell>
											<tgridcell>
												<children>
													<template subtype="source" match="XML">
														<children>
															<template subtype="element" match="waffen">
																<children>
																	<template subtype="element" match="waffe">
																		<children>
																			<template subtype="element" match="nachweisBehoerde">
																				<children>
																					<content/>
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
														<variables/>
													</template>
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
		</children>
	</mainparts>
	<globalparts/>
	<designfragments/>
	<xmltables/>
	<authentic-custom-toolbar-buttons/>
</structure>
